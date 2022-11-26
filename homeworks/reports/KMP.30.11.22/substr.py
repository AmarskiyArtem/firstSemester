def searchForOccurrences(string, substring):
            result = list()
            stringLength = len(string)
            substringLength = len(substring)
            for i in range(stringLength - substringLength + 1):
                for j in range(substringLength):
                    if string[i + j] != substring[j]:
                        break;
                    if j == substringLength - 1:
                        result.append(i)
            return result

string = input()
substring = input()
for x in searchForOccurrences(string, substring):
    print(x, end = ' ')
