#include <cstdio>
#include <cstdlib>

int main()
{
    FILE *input = freopen("time.in", "r", stdin);
    FILE *output = freopen("time.out", "w", stdout);

    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);

    int realTime_sec = 2*(s + m*60 + h*3600);
    h = realTime_sec/3600;
    realTime_sec %= 3600;
    m = realTime_sec/60;
    s = realTime_sec%60;

    printf("%02d:%02d:%02d", h, m, s);

    fclose(input);
    fclose(output);
    return 0;
}
