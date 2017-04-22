$(document).ready(function (event) {

  // 그냥 색깔이 이뻐서
  // $('html').css({
  //   backgroundColor: 'black'
  // })

  // $('div').css({
  //   color: 'skyblue'
  // })

  // // $('.reverse').css({
  // //   color : 'darkblue'
  // // })  // not working

  // setInterval(function () {
  //   $('div').first().appendTo('body')
  // }, 2000)

  // // Example 1 : Event connect
  // $('h1').on('click', function () {
  //   return router(parseClassName(this.className, 0))
  // })

  // $('h1').on({
  //   mouseenter: function () {
  //     $(this).addClass('reverse')
  //   },
  //   mouseleave: function () {
  //     $(this).removeClass('reverse')
  //   }
  // })

  // // $('h1').hover(function(){}, function(){})

  // // module part

  // function parseClassName(classNames, index) {
  //   return classNames.split(' ')[index]
  // }

  // function router(className) {
  //   switch (className) {
  //     case 'div1':
  //       counter('#b1')
  //       break;
  //     case 'div2':
  //       counter('#b2')
  //       break;
  //     case 'div3':
  //       counter('#b3')
  //       break;
  //     default:
  //       console.error('?')
  //       break;
  //   }
  // }

  // function counter(id) {
  //   $(id).html(function (index, html) {
  //     if (html === undefined)
  //       return 1
  //     else
  //       return Number(html) + 1
  //   })
  // }

  // off() : 이벤트 연결 제거
  // off(), off(eventName), off(eventName, function)

  // // $(selected, scope)
  // $('div').click(function(){
  //   beforeVal = Number($('b', this).text()) + 1
  //   $('b', this).text(beforeVal)
  //   var header = $('h1', this).text()
  //   var paragraph = $('b', this).text()
  //   console.log('header : '+ header + ', count : ' + paragraph)
  // })

  // // Canvas Example
  // var canvas = document.getElementById('canvas');
  // var context = canvas.getContext('2d')

  // $(canvas).on({
  //   mousedown: function(e){
  //     var position = $(this).offset();
  //     var x = event.pageX - position.left;
  //     var y = event.pageY - position.top;

  //     context.beginPath();
  //     context.moveTo(x,y);
  //   },
  //   mouseup:function(e){
  //     var position = $(this).offset();
  //     var x = event.pageX - position.left;
  //     var y = event.pageY - position.top;

  //     context.lineTo(x,y);
  //     context.stroke();
  //   }
  // })

  // trigger() : 이벤트 강제 발생, 이벤트 체인으로도 구성 가능
  // trigger(event), trigger(event, data) 

  // 이벤트 확산 방지
  // event.stopPropagation()  : 이벤트 발생이 확산되는 것을 방지
  // event.preventDefault()   : 기본 이벤트 발생을 방지
  // jQuery에서는 return false인 경우 위 두가지를 함께 적용하는 것으로 인식
  // $('a').click(function(event){
  // $(this).css('background-color', 'skyblue')
  // return false;

  // 이벤트 연결 범위 한정 : delegate 방식

  //})

  // // Event : Mouse
  // click, dbclick         : 마우스 버튼을 클릭/더블 클릭할 때 이벤트 발생
  // mousedown, mouseup     : 마우스 버튼을 누를/뗄 때 이벤트 발생
  // mousemove              : 마우스 이동 시 발생
  // mouseenter, mouseleave : 마우스가 요소 경계 외부에서 내부로/내부에서 외부로 이동할 때 이벤트 발생; 주로 이걸 사용한다네
  // mouseout, mouseover    : 마우스가 요소를 벗어날 때/들어올 때 이벤트 발생

  // // Event : Keyboard
  // keydown  : 키보드를 누를 때 이벤트 발생
  // keypress : 글자가 입력될 때 이벤트 발생
  // keyup    : 키보드를 뗄 때 이벤트 발생

  // // keyboard event Example
  // $('textarea', '#div1').keyup(function () {
  //   var inputLength = $(this).val().length
  //   var remain = 150 - inputLength
  //   $('b', '#div1').html(remain)
  // })

  // // Window Event
  // // ready    : 문서 객체가 준비 완료되면
  // // load     : 문서 객체를 불러들일 때 발생
  // // unload   : 문서 객체를 닫을 때 발생
  // // resize   : 윈도 크기를 변화시킬 때 발생
  // // scroll   : 윈도를 스크롤 할 때 발생
  // // error    : 에러가 있을 때 발생

  // // 무한 스크롤 예제
  // for (var i=0;i<20;i++){
  //   $('<h1>Infinity Scroll</h1>').appendTo('body')
  // }
  // $(window).scroll(function(){
  //   var scrollHeight = $(window).scrollTop() + $(window).height()
  //   var documentHeight = $(document).height()
  //   // 200은 오차를 고려한 offset이며 동시에 미리 로드하기 위함이다.
  //   if (scrollHeight > documentHeight-200){
  //     for (var i=0; i<10;i++){
  //       $('<h1>Infinity Scroll</h1>').appendTo('body')
  //     }
  //   }
  // })

  // // Animation
  // // show():커지며 나타남, hide():작아지며 사라짐, toggle():show(); hide();, slideDown() : 슬라이드와 나타남, slideUp() 슬라이드와 사라짐, slideToggle();fadeIn(), fadeOut(); fadeToggle()
  // // $(selected).method(), $(selected).method(speed={slow, normal, fast, ms}), $(selected).method(speed, callback), $(selected).method(speed, easing, callback)
  // $('textarea', '#div1').fadeOut(function () {

  // })

  // // innerfade plug-in
  // // src = https://medienfreunde.de/lab/innerfade/
  // $('#inner-fade').innerfade({
  //   animationtype:'fade',     // or 'slide'
  //   speed : 750,              // or equal jQuery speed option
  //   timeout : 2000,           // interval each animation
  //   type : 'random',          // 'sequence', 'random', 'randomstart'
  //   containerheight : '\''+$(document).height()+'\''  // or numeric.
  // })

  // User Animation
  i = -50;
  $('div').each(function () {
    i += 50
    $(this).css({
      top: i + 'px',
      left: ($(window).width() / 2) + 'px'
    })
  })
  $('div').hover(function () {
    $(this).animate({
      left: $(window).width() - $(this).width() + 'px'
    }, 'slow');
  }, function () {
    $(this).animate({
      left: ($(window).width() / 2) + 'px'
    }, 'slow');
  });
});