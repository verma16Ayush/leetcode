class some():
    def __init__(self):
        self.a = 10
        self.__b = 20


def main():
    Birds = ['a', 'b', 'c', 'd']
    o = Birds
    n = Birds[:]
    o[0] = 'k'
    n[1] = None

    count = 0
    for bird in (Birds, o, n):
        if(bird[0] == 'k'):
            count+=1
        if(bird[1] == None):
            count+=10
        print(count, end='')
main()
