from gpiozero import LED
import tkinter as tk

# LED setup
living_room = LED(17)
bathroom = LED(27)
closet = LED(22)

# Functions
def living_room_on():
    living_room.on()


def living_room_off():
    living_room.off()


def bathroom_on():
    bathroom.on()


def bathroom_off():
    bathroom.off()


def closet_on():
    closet.on()


def closet_off():
    closet.off()


def all_off():
    living_room.off()
    bathroom.off()
    closet.off()
  
# Create window
window = tk.Tk()
window.title("Smart Home Lighting")
window.geometry("400x400")

# Title
title = tk.Label(
    window,
    text="Smart Home Lighting Control",
    font=("Arial", 18)
)
title.pack(pady=20)
# Living Room
tk.Label(
    window,
    text="Living Room",
    font=("Arial", 14)
).pack()

tk.Button(
    window,
    text="ON",
    command=living_room_on,
    width=10
).pack()

tk.Button(
    window,
    text="OFF",
    command=living_room_off,
    width=10
).pack()

# Bathroom
tk.Label(
    window,
    text="Bathroom",
    font=("Arial", 14)
).pack(pady=(15, 0))

tk.Button(
    window,
    text="ON",
    command=bathroom_on,
    width=10
).pack()

tk.Button(
    window,
    text="OFF",
    command=bathroom_off,
    width=10
).pack()

# Closet
tk.Label(
    window,
    text="Closet",
    font=("Arial", 14)
).pack(pady=(15, 0))

tk.Button(
    window,
    text="ON",
    command=closet_on,
    width=10
).pack()

tk.Button(
    window,
    text="OFF",
    command=closet_off,
    width=10
).pack()
# Turn everything off
tk.Button(
    window,
    text="ALL OFF",
    command=all_off,
    width=15
).pack(pady=20)
# Run GUI
window.mainloop()
