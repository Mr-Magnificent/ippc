import re

class Solution(object):
    def isValid(self, code):
        """
        :type code: str
        :rtype: bool
        """
        expr_strt = re.compile(r"(<[A-Z]{1,9}>)")
        expr_end = re.compile(r"(</[A-Z]{1,9}>)")
        expr_data = re.compile(r"(<\!\[CDATA\[.*?\]\]>)")
        
        expr_tag = re.compile(r"<")

        b = expr_data.split(code)
        
        p = []
        for s in b:
            if (expr_data.match(s)):
                p.append(s)
                continue
            p.extend(expr_strt.split(s))

        b = []
        for s in p:
            if (expr_data.match(s)):
                b.append(s)
                continue
            b.extend(expr_end.split(s))
        
        b = filter(lambda e: True if(e != "") else False, b)
        

        if (not expr_strt.match(b[0]) or not expr_end.match(b[len(b) - 1])):
            return False
        
        # if (b[0][1:len(b[0])-1] != b[len(b)-1][2:len(b[len(b)-1])-1]):
        #     return False

        stk = []
        stk.append(b[0][1:len(b[0])-1])

        for ele in b[1:]:
            # print(ele)
            if (len(stk) == 0):
                return False
            
            elif (expr_data.match(ele)):
                continue
            
            elif (expr_strt.match(ele)):
                stk.append(ele[1:len(ele)-1])
            
            else:
                if (expr_end.match(ele)):
                    if (stk[len(stk)-1] == ele[2:len(ele)-1]):
                        stk.pop()
                        
                    else:
                        return False
                elif (expr_tag.findall(ele)):
                    return False
                

        return len(stk) == 0