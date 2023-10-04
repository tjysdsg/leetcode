from sortedcontainers import SortedList, SortedDict, SortedSet


def sorted_list():
    sl = SortedList(['e', 'a', 'c', 'd', 'b'])

    sl.update(['e', 'e', 'e'])
    print(sl)
    print(sl.count('e'))
    print(sl[-3:])
    sl.discard('e')  # only remove one
    sl.remove('c')
    sl.pop(0)
    print(sl)

    print(sl.bisect_left('e'), sl.bisect_right('e'))


def sorted_dict():
    sd = SortedDict({'c': -3, 'a': 1, 'b': 2})
    sd.update({'d': 4, 'e': -4})
    sd.setdefault('f', 6)
    print(sd)
    print(sd.popitem(index=-1))
    print(sd.pop('c'))


def sorted_set():
    ss = SortedSet('abracadabra')
    print(ss)
    SortedSet(['a', 'b', 'c', 'd', 'r'])
    print(ss.bisect_left('c'))
    print(ss.bisect_right('c'))


if __name__ == '__main__':
    print("\nSorted List:")
    sorted_list()
    print("\nSorted Dict:")
    sorted_dict()
    print("\nSorted Set:")
    sorted_set()
