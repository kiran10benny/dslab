 def add_num(*num):
        """
 This function accepts any number of integers and return its sum
        parameters:
        *num :variable length integer arguments
        returns:
        int : sum of all integers passed
        """
        return sum(num)
 print(add_num.__doc__)
 print(f"add_num(1,2,3) = {add_num(1,2,3)}")
 print(f"add_num(2,4) = {add_num(2,4)}")
 print(f"add_num(1,3,5,7,9) = {add_num(1,3,5,7,9)}")
 print(f"add_num(1,2,3,4,5,6,7,8,9) = {add_num(1,2,3,4,5,6,7,8,9)}")
