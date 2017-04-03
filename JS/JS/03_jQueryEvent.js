$(document).ready(function () {
  // 그냥 색깔이 이뻐서
  $('html').css({
    backgroundColor: 'black'
  })

  $('div').css({
    color: 'skyblue',
  })

  setInterval(function () {
    $('div').first().appendTo('body')
  }, 2000)

  // Example 1 : Event connect
  $('h1').on('click', function () {
    return router(parseClassName(this.className, 0))
  })

  $('h1').on({
    mouseenter: function () {
      $(this).addClass('reverse')
    },
    mouseleave: function () {
      $(this).removeClass('reverse')
    }
  })

  // module

  function parseClassName(classNames, index) {
    return classNames.split(' ')[index]
  }

  function router(className) {
    switch (className) {
      case 'div1':
        counter('#b1')
        break;
      case 'div2':
        counter('#b2')
        break;
      case 'div3':
        counter('#b3')
        break;
      default:
        console.error('?')
        break;
    }
  }

  function counter(id) {
    $(id).html(function (index, html) {
      if (html === undefined)
        return 1
      else
        return Number(html) + 1
    })
  }
});