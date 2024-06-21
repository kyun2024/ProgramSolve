T = int(input())

signs = ' 일이삼사오육칠팔구'
digit4 = ' 십백천'
Digit = ' 만억조경해자양구간정재극'

def decode_hangul(han_chr):
    if(han_chr == ' '):
        return []
    idx = ord(han_chr) - ord('가')
    choseong = idx//(21*28)
    jungseong = idx%(21*28)//28
    jongseong = idx%28
    choseong = ['ㄱ', 'ㄲ', 'ㄴ', 'ㄷ', 'ㄸ', 'ㄹ', 'ㅁ', 'ㅂ', 'ㅃ', 'ㅅ', 'ㅆ', 'ㅇ', 'ㅈ', 'ㅉ', 'ㅊ', 'ㅋ', 'ㅌ', 'ㅍ', 'ㅎ'][choseong]
    jungseong = ['ㅏ', 'ㅐ', 'ㅑ', 'ㅒ', 'ㅓ', 'ㅔ', 'ㅕ', 'ㅖ', 'ㅗ', 'ㅘ', 'ㅙ', 'ㅚ', 'ㅛ', 'ㅜ', 'ㅝ', 'ㅞ', 'ㅟ', 'ㅠ', 'ㅡ', 'ㅢ', 'ㅣ'][jungseong]
    jongseong = [' ', 'ㄱ', 'ㄲ', 'ㄳ', 'ㄴ', 'ㄵ', 'ㄶ', 'ㄷ', 'ㄹ', 'ㄺ', 'ㄻ', 'ㄼ', 'ㄽ', 'ㄾ', 'ㄿ', 'ㅀ', 'ㅁ', 'ㅂ', 'ㅄ', 'ㅅ', 'ㅆ', 'ㅇ', 'ㅈ', 'ㅊ', 'ㅋ', 'ㅌ', 'ㅍ', 'ㅎ'][jongseong]
    return [choseong, jungseong, jongseong]

def solve(N, ral):
    l_signs = [s for s in signs if len(set(decode_hangul(s))&set(ral)) == 0]
    l_digit4 = [s for s in digit4 if len(set(decode_hangul(s))&set(ral)) == 0]
    l_Digit = [s for s in Digit if len(set(decode_hangul(s))&set(ral)) == 0]

    l_ns = [i for i, s in enumerate(signs) if len(set(decode_hangul(s))&set(ral)) == 0]
    l_nd = [10**i for i, s in enumerate(digit4) if len(set(decode_hangul(s))&set(ral)) == 0]
    l_nD = [10000**i for i, s in enumerate(Digit) if len(set(decode_hangul(s))&set(ral)) == 0]

    deg_s = len(l_signs)
    deg_d = len(l_digit4)
    deg_D = len(l_Digit)

    MAX_N = deg_s-1
    for i in range(deg_d - 1):
        MAX_N = deg_s - 1 + MAX_N * (deg_s - 1) + MAX_N
    deg_d = MAX_N
    for i in range(deg_D - 1):
        MAX_N = deg_d + MAX_N * deg_d + MAX_N
    
    if(MAX_N < N):
        return -1

    deg_s = len(l_signs)
    deg_d = len(l_digit4)
    deg_D = len(l_Digit)

    res_num = 0
    # res = ''
    d = 0
    while(N>0):
        cs = N%deg_s
        di = d%deg_d
        Di = d//deg_d%deg_D
        # res += '|'+l_Digit[Di]+l_digit4[di]+l_signs[cs]
        res_num += l_ns[cs]*l_nd[di]*l_nD[Di]
        N = N//deg_s
        d += 1

    return res_num


while T>0:
    N, r = map(int, input().split())
    if(r):
        ral = input().split(' ')
    else:
        ral = []
    
    print(solve(N, ral))
    # for n in range(1, N+1):
    #     print(solve(n, ral))
    T-=1