def isAnagram(self, s: str, t: str) -> bool:
        s = list(s)
        s.sort()
        s = "".join(s)
        t = list(t)
        t.sort()
        t = "".join(t)
        if t==s:
            return True
        else:
            return False
