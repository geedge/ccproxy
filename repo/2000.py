import random
import string

# 生成2000个随机字符
random_chars = ''.join(random.choices(string.ascii_letters + string.digits, k=2000))

# 将结果写入txt文件
with open('random_chars.txt', 'w') as f:
    f.write(random_chars)
