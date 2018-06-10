### STACK을 이용하여 중위 표현식을 후위 표현식으로 변환

1. 문자열 파싱
    1. 숫자와 연산자 구분
        1. 숫자 60~69
        2. '\t', ' ', '(', ')', '*', '+', '-', '/'

2. 연산자의 우선순위 구분
```
	int getPriority(char ch){
		int ret = 0;
		switch(ch){
			case '*':
			case '/':
				ret = 2;
				break;
			case '+':
			case '-':
				ret = 1;
				break;
			case '(':
			case ')':
				ret = 0;
				break;
			default:
				ret = -1;
				break;
		}
		return ret;
	}
```

3. STACK/NODE 설계
4. 프로그래밍 설계
	1. 입력
	2. 읽어들인 문자에 대한 상황별 처리
		1. 피연산자  : 출력
		2. 연산자    : STACK의 TOP 연산자와 비교 후 차순위인 경우 STACK POP 출력
					: STACK의 TOP 연산자와 비교 후 최상순위인 경우 출력
				   	: '('인 경우 STACK PUSH
					: ')'인 경우 while(STACK->POP->TYPE == '(') STACK POP 출력 

### STACK을 이용한 후위 표기식 계산

예
A + B * C + (D + E * F)
ABC*+DEF*+
A + B * C * (D + E * F)
ABC*DEF*+*

1. while(peek(stack->top) == 연산자 ){
	read until under 4rd
}
2. res = 배열[i-2] 배열[i] 배열 [i-1] 
3. push(stack, res)
4. 위 과정을 STACK에 더이상 없을 때 까지 반복