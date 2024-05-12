import ctypes
import threading
import time

# Constants for mouse events
MOUSEEVENTF_MOVE = 0x0001
MOUSEEVENTF_ABSOLUTE = 0x8000
MOUSEEVENTF_LEFTDOWN = 0x0002
MOUSEEVENTF_LEFTUP = 0x0004
MOUSEEVENTF_RIGHTDOWN = 0x0008
MOUSEEVENTF_RIGHTUP = 0x0010

# Define function prototype
VkKeyScan = ctypes.windll.user32.VkKeyScanA
VkKeyScan.argtypes = [ctypes.c_char]
VkKeyScan.restype = ctypes.c_short

# Define structures
class MOUSEINPUT(ctypes.Structure):
    _fields_ = [("dx", ctypes.c_long),
                ("dy", ctypes.c_long),
                ("mouseData", ctypes.c_ulong),
                ("dwFlags", ctypes.c_ulong),
                ("time", ctypes.c_ulong),
                ("dwExtraInfo", ctypes.POINTER(ctypes.c_ulong))]

class INPUT(ctypes.Structure):
    _fields_ = [("type", ctypes.c_ulong),
                ("mi", ctypes.POINTER(MOUSEINPUT))]

class POINT(ctypes.Structure):
    _fields_ = [("x", ctypes.c_long),
                ("y", ctypes.c_long)]

# Define global variable
cursor_pos = POINT()

# Function to continuously update cursor position
def update_cursor_position():
    global cursor_pos
    while True:
        ctypes.windll.user32.GetCursorPos(ctypes.byref(cursor_pos))

# Start the thread for updating cursor position
cursor_thread = threading.Thread(target=update_cursor_position)
cursor_thread.daemon = True  # Daemonize the thread so it exits when the main program exits
cursor_thread.start()

# Function to simulate mouse click
def click():
    global cursor_pos

    # Set mouse position
    x, y = cursor_pos.x, cursor_pos.y
    
    # Create input structure
    mouse_input = MOUSEINPUT(x, y, 0, MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, 0, None)
    input = INPUT(ctypes.c_ulong(0), ctypes.pointer(mouse_input))
    
    # Send input
    ctypes.windll.user32.SendInput(1, ctypes.pointer(input), ctypes.sizeof(INPUT))

    # Click
    ctypes.windll.user32.mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0)
    ctypes.windll.user32.mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0)

# Function to check if key is pressed
def is_key_pressed(key):
    virtual_key_code = VkKeyScan(key.encode('ascii'))
    return ctypes.windll.user32.GetAsyncKeyState(virtual_key_code)

# Function to run mouse click in the current position of the cursor until stop_key is pressed
def main():
    stop_key = 's'
    print(f"Press {stop_key} to stop the script.")
    try:
        while True:
            click()  # Click at the currrent position of the cursor
            time.sleep(1/1000)  # Sleep for 1/1000 seconds
            if is_key_pressed(stop_key):
                print("Stopping the script.")
                break
    except KeyboardInterrupt:
        print("Stopping the script.")

if __name__ == "__main__":
    main()
