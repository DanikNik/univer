#!/usr/bin/python3
import re #я буду использовать регулярные выражения для парсинга передаваемой формулы

def make_parsed_exp(exp_list, values_list):
    length = len(values_list)
    in_return = ''
    for i in range(length):
        in_return += exp_list[i]
        in_return += "alpha('"+ values_list[i] +"')"
    in_return += exp_list[-1]
    return in_return

def sum_strings(string1, string2):
    in_return = string1 + string2
    return in_return

def sub_strings(string1, string2):
    if string1[len(string1)-len(string2):] == string2:
        in_return = string1[:len(string1)-len(string2)]
        return in_return
    else:
        return string1

def mul_strings(string1, string2):
    length = min(len(string1), len(string2))
    in_return = ""
    for i in range(length):
        in_return += string1[i]
        in_return += string2[i]
    if length == len(string1):
        in_return += string2[i+1:]
    else:
        in_return += string1[i+1:]
    return in_return

def div_strings(string1, string2):
    length = len(string2)
    temp = ""
    for i in range(length*2):
        if i%2 == 1:
            temp += string1[i]
    if temp == string2:
        in_return = string1[:length*2-1:2] + string1[length*2:]
    else:
        in_return = string1
    return in_return

class alpha:
    def __init__(self, value):
        self.value = value

    def __add__(self, other):
        return alpha(sum_strings(self.value, other.value))

    def __sub__(self, other):
        return alpha(sub_strings(self.value, other.value))

    def __mul__(self, other):
        return alpha(mul_strings(self.value, other.value))

    def __truediv__(self, other):
        return alpha(div_strings(self.value, other.value))
    def __repr__(self):
        return self.value

if __name__ == '__main__':
    pattern = re.compile(r"[^\(\)\+\-\*/ ]+")
    #OPERATORS = {'+':(1, sum_strings), '-':(1, sub_strings), '*':(2, mult_strings), '/':(2, div_strings)} # 1 elem - priority, 2 elem - function2call

    expression = str(input("[>] Enter expression: "))
    print(expression)

    exp_list = list(pattern.split(expression))
    values_list = list(pattern.findall(expression))

    print(exp_list, len(exp_list))
    print(values_list, len(values_list))
    print('\n')
    new_expression = make_parsed_exp(exp_list, values_list)
    print(new_expression)
    print('\n')
    result = eval(new_expression)
    print(result)
#((index - ex) - d) + gst * osr + (an + k + oh) / (n + o)
