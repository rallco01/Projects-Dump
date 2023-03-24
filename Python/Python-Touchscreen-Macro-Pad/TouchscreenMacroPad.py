import tkinter as tk
from tkinter import * 
from tkinter import ttk
from tkinter.ttk import *
import os
import csv
    
class CreateButtons:
    def __init__(self, master):
        self.master = master

        # Configure the grid columns
        for i in range(0, 10):
            self.master.grid_columnconfigure(i, minsize=100)
            
        # Configure the grid rows
        for i in range(0, 6):
            self.master.grid_rowconfigure(i, minsize=100)

        # Initialise button size
        self.buttonHeight = 100
        self.buttonWidth = 100

        # Initialise the button image and button dicts
        self.buttonImage = {}
        self.buttonObj = {}

        # Create the buttons reqauired to modify the GUI
        self.reloadButtonImage = PhotoImage(master=self.master, file="Resources\Images\ReloadButton.png")
        self.reloadButton = tk.Button(self.master, text="Reload", width=self.buttonWidth, height=self.buttonHeight, command=self.refresh, bd=0, highlightthickness=0, image=self.reloadButtonImage)
        self.reloadButton.grid(row=0, column=0)    

        self.createButtonImage = PhotoImage(master=self.master, file="Resources\Images\CreateNewButton.png")
        self.createButtonButton = tk.Button(self.master, text="Create", width=self.buttonWidth, height=self.buttonHeight, command=self.createButtonGui, bd=0, highlightthickness=0, image=self.createButtonImage)
        self.createButtonButton.grid(row=0, column=1)    
        
        self.deleteButtonImage = PhotoImage(master=self.master, file="Resources\Images\DeleteButton.png")
        self.deleteButtonButton = tk.Button(self.master, text="Delete", width=self.buttonWidth, height=self.buttonHeight, command=self.deleteButtonGui, bd=0, highlightthickness=0, image=self.deleteButtonImage)
        self.deleteButtonButton.grid(row=0, column=2)
        
        # Read the CSV that holds the buttons
        with open("Resources\Buttons.csv", 'r') as file:
                reader = csv.reader(file)
                self.header = next(reader)
                self.buttons = []
                for button in reader:
                    self.buttons.append(button)
        
        # Create the buttons from the list
        for button in self.buttons:
            text = button[0]
            imgPath = button[1]
            script = button[4]

            def runButtonAction(x = script):
                os.system(x)

            self.buttonImage[text] = PhotoImage(master=self.master, file="Resources\Images\{}".format(imgPath))
            self.buttonObj[text] = tk.Button(self.master, text=text, width=self.buttonWidth, height=self.buttonHeight, command=runButtonAction, bd=0, highlightthickness=0, image=self.buttonImage[text])
            self.buttonObj[text].grid(row=button[2], column=button[3])

        while True:
            self.master.update_idletasks()
            self.master.update()
    
    def __del__(self):
        del self

    def refresh(self):
        self.__del__()
        self.__init__(self.master)

    def createButtonGui(self):
        
        def gridSpaceTaken():
            # Check if it's trying to place a button on the essential button spaces
            if(self.rowEntry.get() == "0" and self.columnEntry.get() <= "2"):
                    return FALSE

            #Create a list of occupied grid spaces
            existingButtons = []

            for key in self.buttonObj.keys():
                buttonCords=self.buttonObj[key].grid_info()
                buttonStr="{},{}".format(buttonCords["row"], buttonCords["column"])
                existingButtons.append(buttonStr)

            # Check if the input coords overlap an existing button
            if "{},{}".format(self.rowEntry.get(), self.columnEntry.get()) in existingButtons:
                return FALSE

            return TRUE
        
        def inputValidation():
            errorStr = ""

            # Check if any of the inputs are empty
            if not((not self.nameEntry.get()) and (not self.imageEntry.get()) and (not self.rowEntry.get()) and (not self.columnEntry.get()) and (not self.actionEntry.get())):
                if self.nameEntry.get() in self.buttonObj: 
                    errorStr += "Button with that name already exists.\n"
                
                # Check if the image exists
                if(not os.path.exists(self.imageEntry.get())):
                    errorStr += "Image Doesn't exist.\n"
                else:
                    # Check if the path input is an image format
                    if(not self.imageEntry.get().lower().endswith(('.png', '.jpg', '.jpeg', '.tiff', '.bmp', '.gif'))):
                        errorStr += "Image is not a supported image type.\nSupoorted image types are: .png .jpg .jpeg .tiff .bmp .gif\n"

                # Check that the row and column inputs are the correct format
                if ((not self.rowEntry.get().isdigit()) or (not self.columnEntry.get().isdigit())):
                    errorStr += "Row and column fields can only be whole numbers.\n"
                else:
                    # Check that the specified grid space isn't outside the scope
                    if ((int(self.rowEntry.get()) > 5) or (int(self.columnEntry.get())>9)):
                        errorStr += "Invalid coords, buttons cannot be placed in a row greater than 5\nor a column greater than 9.\n"
                    else:  
                        # Check that the grid space is empty
                        if not gridSpaceTaken():  
                            errorStr += "Inavlid coords, a button already exists there.\n"              
            else:
                errorStr += "No fields can be left blank.\n"


            return errorStr

        def submit():
            errorStr = inputValidation()

            if not errorStr:
                buttonStr = "{},{},{},{},{}\n".format(self.nameEntry.get(), self.imageEntry.get(), self.rowEntry.get(), self.columnEntry.get(), self.actionEntry.get())

                with open("Buttons.csv", 'a') as file:
                    file.write(buttonStr)
            
                #Close the window
                self.createButtonWindow.destroy()
                self.createButtonWindow.update()

                #Refresh the buttons from CSV so as to include the newly added button
                self.refresh()
            else:
                errorPop = Toplevel(self.createButtonWindow)
                errorPop.title("Error")
                errorPop.minsize(200, 50)
                Label(errorPop, text=errorStr).pack()
                Button(errorPop, text="ok", command=errorPop.destroy).pack()

        # --------------------===================++++++++++++++++++++===================-------------------- #
        #                                        Create the form GUI                                         #
        # --------------------===================++++++++++++++++++++===================-------------------- #

        self.createButtonWindow = Toplevel(self.master)
        self.createButtonWindow.title("Create a new button")

        Label(self.createButtonWindow, text ="Button Name").grid(sticky = W, row=0, column=0)
        self.nameEntry = Entry(self.createButtonWindow)
        self.nameEntry.grid(row=0, column=1)

        Label(self.createButtonWindow, text ="Button Action (cmd command)").grid(sticky = W, row=1, column=0)
        self.actionEntry = Entry(self.createButtonWindow)
        self.actionEntry.grid(row=1, column=1)

        Label(self.createButtonWindow, text ="Button Image (full path + image name)").grid(sticky = W, row=2, column=0)
        self.imageEntry = Entry(self.createButtonWindow)
        self.imageEntry.grid(row=2, column=1)

        Label(self.createButtonWindow, text ="Button Row").grid(sticky = W, row=3, column=0)
        self.rowEntry = Entry(self.createButtonWindow)
        self.rowEntry.grid(row=3, column=1)

        Label(self.createButtonWindow, text ="Button Column").grid(sticky = W, row=4, column=0)
        self.columnEntry = Entry(self.createButtonWindow)
        self.columnEntry.grid(row=4, column=1)

        submitButton = Button(self.createButtonWindow, text="Create", command=submit)
        submitButton.grid(row=5, column=0, columnspan=2)
    
    def deleteButtonGui(self):
        def submit():
            counter = 0
            if any(clicked.get() in i for i in self.buttons):
                for button in self.buttons:
                    if clicked.get() in button:
                        break
                    else:
                        counter += 1
                del self.buttons[counter]
                with open("Buttons.csv", 'w', newline='') as file:
                    writer = csv.writer(file)
                    writer.writerow(self.header)
                    writer.writerows(self.buttons)
                self.refresh()
            else:
                errorPop = Toplevel(self.deleteButtonWindow)
                errorPop.title("Error")
                errorPop.minsize(200, 50)
                Label(errorPop, text="Button Doesn't exist\n").pack()
                Button(errorPop, text="ok", command=errorPop.destroy).pack()

        # --------------------===================++++++++++++++++++++===================-------------------- #
        #                                        Create the form GUI                                         #
        # --------------------===================++++++++++++++++++++===================-------------------- #

        self.deleteButtonWindow = Toplevel(self.master)
        self.deleteButtonWindow.title("Delete a button")
        self.deleteButtonWindow.minsize(200, 50)

        Label(self.deleteButtonWindow, text="WARNING: Make sure you select the correct button,\nonce you have deleted a button, this action is irreversible.").pack()

        clicked = StringVar()
        clicked.set(list(self.buttonObj.keys())[0])

        self.buttonMenu = OptionMenu(self.deleteButtonWindow, clicked, list(self.buttonObj.keys())[0], *list(self.buttonObj.keys()))
        self.buttonMenu.pack()

        submitButton = Button(self.deleteButtonWindow, text="Delete", command=submit)
        submitButton.pack()

# --------------------===================++++++++++++++++++++===================-------------------- #
#                                           Create the GUI                                           #
# --------------------===================++++++++++++++++++++===================-------------------- #

# Define window 
windowW = 1024
windowH = 600

root = Tk(className="Macro Experiment")
root.geometry(str(windowW) + "x" + str(windowH))
root.attributes('-fullscreen',True)

gui = CreateButtons(root)