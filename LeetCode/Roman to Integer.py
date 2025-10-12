class Solution:
    def romanToInt(self, s: str) -> int:
        roman_to_int = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }

        dec = 0
        last_dgt = 0

        for i in s:
            if roman_to_int[i] > last_dgt:
                dec += roman_to_int[i] - 2*last_dgt
            else:
                dec += roman_to_int[i]
            last_dgt = roman_to_int[i]

        return dec