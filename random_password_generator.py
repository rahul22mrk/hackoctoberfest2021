import random
from win10toast import ToastNotifier
import pyperclip
password_length=20
password=''
characters="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghjiklmnopqrstuvwxyz1234567890!@#_'""$%&*/\-+"
for i in range(password_length):
    password+=characters[random.randint(0,len(characters)-1)]
toaster=ToastNotifier()
toaster.show_toast(" Do You need a strong password? Use These:) ",
password+ "is copied to your clipboard",
icon_path=None,
duration=10)
pyperclip.copy(password)
