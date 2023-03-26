import itertools

import numpy as np


def main():
    ans = 0
    n, m = map(int, input().split())
    ll = np.array([list(map(int, input().split())) for l in range(n)])
    for i, j in list(itertools.combinations(range(m), 2)):
        ans = max(ans, ll[:, [i, j]].max(axis=1).sum())
    print(ans)


if __name__ == "__main__":
    main()
