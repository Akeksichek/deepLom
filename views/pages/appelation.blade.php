<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://fonts.googleapis.com/css2?family=Inter&display=swap" rel="stylesheet">
    <link rel="stylesheet" href="{{asset('css/style/reset.css')}}">
    <link rel="stylesheet" href="{{asset('css/appStyle.css')}}">
    <title>Document</title>
</head>
<body>
    <nav class="nav">
        <div class="container">
            <div class="navLine">
                <header class="header">
                  <div class="container">
                    <nav class="navLine">
                      <p class="textNav"><a class="textNavA" href="{{ route('createOrder') }}">Записаться</a></p>
                      <p class="textNav"><a class="textNavA" href="{{ route('equipment') }}">О нас</a></p>
                      <p class="logoNav"><a href="{{ route('index') }}"><img src="../src/logo.png" alt=""></a></p>
                      <p class="textNav"><a class="textNavA" href="{{ route('index') }}">Главная</a></p>
                      <p class="textNav"><a class="textNavA btnNav" href="logout.php" id="logOpen">выход</a></p>
                    </nav>
                  </div>
                </header>
            </div>
        </div>
    </nav>
    <div class="container">
    <div class="appBlock">
          <p class="topTx">Чат с администрацией</p>
          <div class="appChat">
          <div class="msgBlock">
              <!-- Вывод сообщений на экран -->
              <div class="msgWin"><p id="msg" name="msg"></p></div>
            </div>
            <form method="post" action="jsonRec.php" class="msgInput">
              <!-- Ввод сообщения пользователем -->
              <input class="msgRec" id="msgInput" type="text" name="msg" placeholder="Введите сообщение">
              <button class="msgSend"><img src="../src/phoneIcon.png" alt=""></button>
            </form>
          </div>
      </div>
    </div>
    <script src="mainApp.js"></script>
</body>
</html>