def makePrefix(string):
    prefix = [0] * len(string)
    begin, end = 0, 1
    while end < len(string):
        if string[begin] == string[end]:
            prefix[end] = begin + 1
            begin += 1
            end += 1
        else:
            if begin == 0:
                prefix[end] = 0
                end += 1
            else:
                begin = prefix[begin-1]
    return prefix

def searchForOccurrences(string, substring, prefix):
                    result = list()
                    i = j = 0
                    while i < len(string):
                        if substring[j] == string[i]:
                            i += 1
                            j += 1
                            if j == len(substring):
                                result.append(i - len(substring))
                                j = prefix[j - 1]
                        else:
                            if j > 0:
                                j = prefix[j - 1]
                            else:
                                i += 1
                    return result                        
                    
string = input()
substring = input()
prefix = makePrefix(substring);
k = searchForOccurrences(string, substring, prefix)
for x in k:
    print(x, end = ' ')
