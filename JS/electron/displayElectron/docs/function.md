# displayElectron

2017.02.07


1. loginModal
+ event.preventDefault()

  이벤트를 취소할 수 있는 경우, 이벤트의 전파를 막지 않고 이벤트를 취소한다. (즉 사용자가 알아서 처리하겠다 이말씀.) 단, 이벤트를 취소하는 도중 preventDefault를 호출하는 경우 브라우저의 구현에 의해 처리되는 액션에 대한 기존 동작이 작동하지 않고 그 결과 이벤트가 발생하지 않는다. 또한 DOM을 통한 이벤트의 전파를 막지 않기 때문에, 이를 막기 위해서는 event.stopPropagation을 사용해야 한다.