<!DOCTYPE html>
<html>
<head>
  <title> Digital Clock </title>
  <style>
    body{
      background-color: black;
    }
    .Clock{
      position: absolute;
      color: green'
      top: 50%;
      left: 50%;
      transform: translateX (-50%);
      font-size: 60px;
      font-family: Orbitron;
    }
  </style>

</head>
<body>
<div id = 'DigitalClock'> </div>
<script type = 'text/javascript'>
function showTime() {
  var date = new Date();
  var h = date.getHours();
  var m = date.getMinutes();
  var s = date.getSeconds();
  var session = 'AM';
  
  if (h == 0){
    h = 12; //12 hours format
  }
  
  if (h > 12){
    h = h - 12; //12 hours format
    session = 'PM';
  } 

  /*
  if (h < 10){ // 0 - 9
    h = '0' + h ;
  }
  
  if (m < 10){ // 0 - 9
    m = '0' + m ;
  }
   
  if (s < 10){ // 0 - 9
    s = '0' + s ;
  }
  */
  
  h = (h < 10) ? '0' + h : h;
  m = (m < 10) ? '0' + m : m;
  s = (s < 10) ? '0' + s : s;
  
  document.getElementById('DigitalClock').innerHTML = h + ':' + m + ':' + s + ' ' + session;
  setTimeout(showTime, 1000);
}
</script>
</body>
</html>
