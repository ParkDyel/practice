exports.dart = (input) => {

}

operandFlag = ['S', 'D', 'T'];
optionFlag = ['*', '#'];
ptrFlag = ['first', 'second', 'third']

let parsingString = (input) => {
  // S,T,D,*,#을 만나면 나눠주도록 하자.
  return ret;
}

/*
[모질라 재단의 래퍼런스](https://developer.mozilla.org/ko/docs/Web/JavaScript/Guide/)
[연습하고 싶을 때 사용할 수 있는 테스트 사이트 regexr.com](https://regexr.com/)
str.replace(regexp|substr, newSubStr|function)
  - 인자
    - regexp (pattern) : 정규식(RegExp) 객체 또는 리터럴. 이 정규식에 매칭되는 부분들은 두번째 파라미터의 반환값으로 교체되어 집니다.
    - substr (pattern) : 새로운 문자열에 의해서 교체당할 문자열(String).  정규식이 아닌 글자 그대로의 문자열로 처리된다. 오직 첫 번째 일치되는 문자열만이 교체된다.
    - newSubStr (replacement) : 첫번째 파라미터를 대신할 문자열(String). 여러가지 대체 패턴들이 지원됩니다. 아래의 "매개변수가 string으로 지정되었을 때" 섹션을 참고하세요.
    - function (replacement) 첫번째 파라미터를 대신할 새로운 문자열을 생성하기 위해 호출될 function. 이 function에 제공되는 인자들은 아래  "매개변수가 function으로  정되었을 때" 섹션에 기술되어 있습니다.
  - 반환값
    - 어떤 패턴에 일치하는 일부 또는 모든 부분이 교체된 새로운 문자열
정규표현식(정규식)
  생성 : 
    ```
    var re = /ab+c/;
    var re = new RegExp("ab+c");
    ```
  정규식의 특수문자(메타문자)
    \ : 흔히 아는 특수문자 표현 기호
    ^ : 첫 시작 문자라는 걸 표기. 예를 들어 ^A는 Ae에만 해당되지 e Af는 해당되지 않는다.
    $ : 마지막 문자라는 걸 표기. ^와 반대로 $t는 later에는 해당되지 않고 eat에만 해당된다.
    * : 0회 이상 연속으로 반복되는 앞선 문자에 일치. 예를 들어 /bo* /(아시다시피 * /는 닫는기호라 띄어쓰기로 표기)는 b, bo, boo 등과 일치한다. o에는 해당되지 않는다.
    + : 1회 이상 연속으로 반복되는 앞선 문자에 일치. 예를 들어 /ba+/는 ba, baa, baaa 등과 일치한다. 하지만 b에는 해당되지 않는다.
    ? : 0 또는 1회 반복되는 앞선 문자에 일치합니다. {0,1}와 동일합니다. 예를 들어, /e?le?/ 는 "angel"의 'el' 에 일치하고, "angle"의 'le' 에 일치하고 또한 "oslo" 의 'l'에도 일치합니다. _이건 잘 이해가 안된다. e le가 왜 el에 일치하는가 e?le?는 e 또는 le에만 해당이되면 되는건가 싶다. 뭔 소린지 모르겠다. 써봐야한다._ +와 *와 같은 탐욕스러운 문자와 함께쓰면 하나만 가져온다 예를 들어 /\d+/를 "123abc"에 적용시키면 "123"이 일치합니다. 그러나 /\d+?/를 같은 문자열에 적용시키면 오직 "1"만 일치한다.
    . : 임의의 한 문자에 일치합니다. 예를 들어 /.n/는 on, an에 일치하지만 nay에는 일치하지 않는다.
    ( X ) : 포획 괄호(capturing parentheses)에 일치하는 것을 기억한다.
    (?:X) : 'x'에 일치하지만 일치한 것을 기억하지 않습니다. 괄호는 비포획 괄호(non-capturing parentheses)라고 불리우고, 정규식 연산자가 같이 동작할 수 있게 하위 표현을 정의할 수 있습니다. 정규식 예제/(?:foo){1,2}/을 생각해보세요. 만약 정규식이 /foo{1,2}/라면, {1,2}는 'foo'의 마지막 'o' 에만 적용됩니다. 비포획 괄호과 같이 쓰인다면, {1,2}는 단어 'foo' 전체에 적용됩니다. _아래 {n,m}에 대해 살펴봐야지 이해가된다. 뭔 개소린가 했다.
    x(?=y) : 오직 'y'가 뒤따라오는'x'에만 일치합니다. 이것은 lookahead 라고 불립니다. 예를 들어, /Jack(?=Sprat)/ 는 'Sprat'가 뒤따라오는 'Jack' 에만 일치합니다. /Jack(?=Sprat|Frost)/는 'Sprat' 또는 'Frost'가 뒤따라오는 'Jack'에만 일치합니다. 그러나, 'Sprat' 및 'Frost 는 일치 결과의 일부가 아닙니다. 이건 이해가 된다. x를 찾는데 뒤에 y가 따라오는 x만 찾는거지.
    x(!=y) : 이건 x(?=y)와 반대로 오직 'y'가 뒤따라오지 않는 'x'에만 일치합니다. 이것은 negated lookahead 라고 불립니다. 예를 들어, /\d+(?!\.)/는 소숫점이 뒤따라오지 않는 숫자에 일치합니다. 정규식 /\d+(?!\.)/.exec("3.141")는 '3.141' 이 아닌 '141'에 일치합니다.
    x|y : 'x' 또는 'y'에 일치합니다. 예들 들어, /green|red/는 "green apple"의 'green'에 일치하고, "red apple."의 'red'에 일치합니다.
    {n} : 조건 문자가 n 번 나타날 경우에 일치합니다. N은 절대로 양의 정수이어야만 합니다. 예를 들어, /a{2}/는 "candy,"의 'a'에는 일치하지 않지만, "caandy,"의 모든 a 와, "caaandy."의 첫 두 a 에는 일치합니다.
    {n,m} : 앞 문자가 최소n개, 최대 m개가 나타나면 일치합니다. 이때 n과 m은 양의 정수이고, n <= m를 만족해야 하고, m이 생략된다면, m은 ∞로 취급됩니다. 예를 들어, /a{1,3}/는 "cndy"에서 아무것도 일치하지 않지만, "caandy,"의 첫 두 a 와 "caaaaaaandy"의 첫 세 a 에 일치합니다. "caaaaaaandy"에서 더 많은 a 들이 있지만, "aaa"만 일치한다는 점을 주목하세요.
    [xyz] : 문자셋(Character set) 입니다. 이 패턴 타입은 괄호 안의 이스케이프 시퀀스를 포함한 어떤 한 문자에 일치합니다. 점(.) 이나 별표 (*) 같은 특수 문자는 문자셋에서는 특수 문자가 아닙니다. 따라서 이스케이프시킬 필요가 없습니다. 다음의 예제에서 보여주는 것 처럼 , 하이픈을 을 이용하여 문자의 범위를 지정해 줄 수 있습니다. 패턴 [abcd] 처럼 일치하는, 패턴 [a-d] 는 "brisket"의 'b' 에 일치하고, "city"의 'c' 에 일치합니다. 패턴 /[a-z.]+/ 와 /[\w.]+/ 는 "test.i.ng" 전체 문자열이 일치합니다.
    [^xyz] : [xyz]와 반대로 음의 문자셋(negated character set) 또는 보수 문자셋(complemented character set)입니다. 괄호 안에 동봉되지 않은 어떤 문자든 일치합니다. 하이픈을 이용하여 문자의 범위를 지정할 수 있습니다. 일반적인 문자셋에서 작동하는 모든것은 여기에서도 작동합니다. 예를 들어, 패턴[^abc]는 패턴[^a-c]와 동일합니다. 두 패턴은 최초로 "brisket"의 'r', "chop."의 'h' 에 일치합니다.
    \w : 밑줄 문자를 포함한 영숫자 문자에 일치합니다. [A-Za-z0-9_] 와 동일합니다. 예를 들어, /\w/는 "apple,"의 'a' 에 일치하고, "$5.28,"의 '5'에 일치하고,"3D."의 '3'에 일치합니다.
    \W : \w와 반대로 비 단어 문자에 일치합니다. 
    \s : 스페이스, 탭, 폼피드, 줄 바꿈 문자등을 포함한 하나의 공백 문자에 일치합니다. [ \f\n\r\t\v​\u00a0\u1680​\u180e\u2000​-\u200a​\u2028\u2029\u202f\u205f​\u3000] 와 동일합니다. 예를 들어, /\s\w* /는 "foo bar."의 ' bar'에 일치합니다.
    \S : \s와 반대로 공백 문자가 아닌 하나의 문자에 일치합니다. 
    \d : 숫자 문자에 일치합니다. [0-9]와 동일합니다. 예를 들어, /\d/ 또는 /[0-9]/는 "B2 is the suite number."에서 '2'에 일치합니다.
    \D : \d와 반대로 숫자 문자가 아닌 문자에 일치합니다.
    \b : 단어의 경계와 일치합니다. 단어의 경계는 단어 문자가 뒤따라오지 않는 위치나, 단어 글자의 앞에서 일치합니다. 단어의 경계는 일치하는 것에 포함되지 않는다는것을 숙지하세요. 다른 말로는, 단어의 경계에 일치하는 것의 길이는 0 입니다. (패턴 [\b]와 혼동하지 마세요.) 예를 들어 /\bm/는 "moon"의 'm'에 일치합니다. /oo\b/ 는 'oo'를 뒤따라오는 'n' 은 단어 문자이기 때문에, "moon"의 'oo'에 일치하지 않습니다. /oon\b/는 "moon"의 'oon'에 일치합니다. 왜냐하면, 'oon'은 문자열의 끝이라서 뒤따라오는 단어 문자가 없기 때문입니다. /\w\b\w/는 어떤 것에도 일치하지 않습니다. 왜냐하면, 단어 문자는 절대로 비 단어 문자와 단어 문자 두개가 뒤따라올수 없기 때문입니다. 이때 강세 표시가 있는 영어(그리스어?)는 단어분리로 취급된다. 결국 영어아니면 말짱묵.
    \B : 단어의 경계가 아닌 곳에 일치합니다. 다시말해, 이 특수문자는 이전 문자와 다음 문자가 같은 타입인 곳에 매치됩니다. 여기서 같은 타입이란 두 문자가 모두 단어이거나, 모두 비 단어(non-word)인 것을 말합니다. 문자열의 시작과 끝은 비 단어로 여겨집니다. 예를 들어, /\B../는 "noonday"의 'oo'에 일치하고, /y\B./는 "possibly yesterday."의 'ye'에 일치합니다.
  
  정규식에서 쓰이는 메소드
    exec	  일치하는 문자열을 찾는 RegExp 메소드입니다. 정보를 가지고 있는 배열을 반환합니다.
    test    일치하는 문자열을 검사하는 RegExp 메소드 입니다. true 나 false를 반환합니다.
    match	  일치하는 문자열을 찾는 String 메소드입니다. 정보를 가지고 있는 배열을 반환하거나 일치하지 않는 부분을 null로 반환합니다.
    search	일치하는 문자열을 검사하는 String 메소드입니다. 일치하는 인덱스를 반환하거나 검색에 실패할 시 -1을 반환합니다.
    replace	일치하는 문자열을 찾는 String 메소드입니다. 일치하는 문자열을 replacement 로 대체합니다.
    split	정규표현식 or 고정된 문자열로 대상 문자열을 나누어 배열로 반환하는 String 메서드입니다.
  정규식 반환값
    myArray	    	      The matched string and all remembered substrings.	  // ["dbbd", "bb"]
    myArray.index	      The 0-based index of the match in the input string.	// 1
    myArray.input       The original string.	        //" cdbbdbsbz"
    myArray.[0]	        The last matched characters.	//  "dbbd"
    myRegExp.lastIndex	The index at which to start the next match. (This property is set only if the regular expression uses the g option, described in Advanced Searching With Flags.)	//5
    myRegExp.source	    The text of the pattern. Updated at the time that the regular expression is created, not executed.	// "d(b+)d"
  패턴화된 부분 문자열 일치 사용하기
    정규식 패턴에서 소괄호를 포함하는 것은 기억되는 서브매칭에 해당하는 것을 발생시킵니다. 예를들면, /a(b)c/ 는 'abc' 와 매칭시키고 'b'를 기억합니다. 이러한 소괄호가 쳐진 일치하는 문자열을 불러오기 위해, 배열 요소 [1], ..., [n] 를 사용합니다.소괄호가 가능한 문자열의 수는 제한이 없습니다. 반환된 배열은 찾아낸 모든 것들을 갖고 있습니다. 다음의 예는 소괄호가 쳐진 일치하는 문자열들을 어떻게 이용하는지 보여 주고 있습니다. 다음의 예는 문자열의 단어를 바꾸기 위해 replace() 메소드를 이용하고 있습니다. 글자를 바꾸기 위해, 이 스크립트는 첫번째와 두번째 소괄호가 쳐진 일치하는 문자열을 의미하는 대체물의 $1 과 $2 를 사용하고 있습니다.
    ```
    var re = /(\w+)\s(\w+)/;
    var str = "John Smith";
    var newstr = str.replace(re, "$2, $1"); //"Smith, John"
  플래그를 사용한 고급검색
    정규식은 전반적이고 대소문자를 구분하지 않는 검색을  따르는 네가지 선택적인 표기 방식이 있습니다.
      g	Global search. ^문자가 문장이 아닌 문서의 처음에, $ 문자가 문장의 끝(라인 피드 \n)이 아닌 주어진 문자열의 끝에 매치되게 변경한다.
      i	Case-insensitive search. 패턴을 대소문자 구분 없이 검사한다. 이 변경자를 사용할 경우 [a-z]로만 검사해도 자동으로 [a-zA-Z]와 같은 기능을 하게 된다. 영어가 아닌 언어(독일어, 프랑스어 등)를 다룰 때에는 버그 가능성이 있으므로 쓰지 않는 게 좋다. 대소문자라는 개념이 없는 한글, 한자, 가나문자는 이 패턴 변경자가 아무 역할도 하지 않는다.
      m	주어진 문자열에 줄바꿈이 있을 경우, 여러 줄로 취급하여 검사한다. (줄바꿈이 없다면 써도 의미가 없다.) 원래 정규표현식을 쓸 때 줄바꿈은 무시되는데, 이걸 사용하면 줄바꿈을 적용해서 검사한다. 그리고 ^은 한 줄의 시작, $는 한 줄의 끝으로 의미가 달라진다.
      y	Perform a "sticky" search that matches starting at the current position in the target string.
*/