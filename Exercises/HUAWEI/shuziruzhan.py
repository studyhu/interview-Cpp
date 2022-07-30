import sys

def merge(str1):
    arr = str1.split()
    res = []
    for item in arr:
        item = int(item)
        res.append(item)
        len_res = len(res)
        temp_sum = 0
        for i in range(len_res-2, -1, -1):
            temp_sum += res[i]
            if temp_sum < item:
                continue
            elif temp_sum == item:
                item = 2*item
                if i>0 and res[i-1] == item:
                    temp_sum = 0
                    continue
                else:
                    res = res[:i]
                    res.append(item)
                    break
            else:
                break
    return res


if __name__ == '__main__':
    str1 = sys.stdin.readline().strip('\n')
    res = merge(str1)
    print(res)