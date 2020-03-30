from tkinter import *
from tkinter.ttk import *
from tkinter import filedialog, messagebox

import sys

import os
from os import path

from distutils.dir_util import copy_tree

script_path = os.path.dirname(os.path.realpath(__file__))

root = Tk()
root.title("Energia patcher")

lbl = Label(root, text="Patching Energia...", width=50)
lbl.grid(column=0, row=0)

pbar = Progressbar(root, mode='indeterminate')
pbar.grid(column=0, row=1, sticky='WE')
pbar.start(15)

# Ask user to select energia folder
selected_folder = filedialog.askdirectory(title="Select Energia Directory")

try:
    # Make sure this is an energia directory
    files = os.listdir(selected_folder)

    # Handle macos
    if selected_folder.endswith("Energia.app"):
        selected_folder = path.join(selected_folder, "Contents", "Java")

    # Make sure folder exists
    if not path.exists(path.join(selected_folder, "hardware")):
        messagebox.showerror("Invalid direcoty!", "The selected folder did not contain an energia install.")
        exit()

    # Merge the hardware folder
    copy_tree(path.join(script_path, "hardware"), path.join(selected_folder, "hardware"))

    # Append the new boards txt data
    data = ""
    with open(path.join(selected_folder, "hardware", "energia", "msp430", "append_to_boards.txt"), "r") as f:
        data = f.read()
    with open(path.join(selected_folder, "hardware", "energia", "msp430", "boards.txt"), "a") as f:
        f.write(data)

    # Delete append_to_boards.txt
    os.remove(path.join(selected_folder, "hardware", "energia", "msp430", "append_to_boards.txt"))
except Exception as e:
    messagebox.showerror("Error patching energia!", str(sys.exc_info()[0]))
    raise e

messagebox.showinfo("Success", "Successfully patched energia install.")