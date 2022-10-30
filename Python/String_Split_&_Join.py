# Name : ILYAS AHMED
# Date : 10/24/2022

def split_and_join(line):
    # write your code here
    a = line.split(" ")
    b = "-".join(a)
    return b
if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)
