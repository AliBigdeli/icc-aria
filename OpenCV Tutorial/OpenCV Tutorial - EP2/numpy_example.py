# وارد کردن کتابخانه با تخصیص یک نام دیگر
import numpy as np
# آرایه یک بعدی را ایجاد کنید
arr = np.array([5, 10, 15])
# برای چاپ نوع داده
print (arr.dtype)
# چاپ int64
# برای چاپ شکل آرایه.
print (arr.shape)
# Prints "(3,)"
#دسترسی به ارزش ذخیره شده و چاپ آنها.
print (arr[0], arr[1], arr[2])
# Prints "5 10 15"
#ارزش آرایه را می توان به طور مستقیم تغییر داد
arr[2] = 35
# برای چاپ کل آرایه.
print (arr)
# Prints "[5, 10, 35]"
# یک آرایه 2 بعدی ایجاد کنید
twoArr = np.array([[5,10],[15,20],[25,30]])
# برای چاپ شکل آرایه.
print (twoArr.shape)
# Prints "(3,2)"
# دسترسی به ارزش ذخیره شده و چاپ آنها.
print (twoArr[0, 0], twoArr[0, 1], twoArr[1, 0])
# Prints "5 10 15"
# برای چاپ کل آرایه.
print (twoArr)
# Prints "[[ 5 10], [15 20],  [25 30]]"
