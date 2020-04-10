#include <stdio.h>

int main() {
    //递归
    int n = fbn(10);
    printf("n=%d", n);

    //有一堆桃子，猴子第一天吃了其中的一半，并再多吃了一个!以后每天猴子都吃其中的一半，然后再多吃一个。当到第十天时，想再吃时(还没吃)，发现只有 1 个桃子了。问题:最初共多少个桃子?
    int p = peach(1);
    printf("peach=%d", p);

}

int fbn(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fbn(n - 1) + fbn(n - 2);
    }
}

int peach(int day) {
    if (day == 10) {
        return 1;
    } else if (day < 10) {
        return (peach(day + 1) + 1) * 2;
    }
}
