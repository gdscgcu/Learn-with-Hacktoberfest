<!DOCTYPE html>
<html>
<head>
  <title> Digital Clock </title>
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
    
  if (h > 12){
    h = h - 12; //12 hours format
    session = 'PM';
    
  if (h < 10){
    h = 12; //12 hours format
  
  document.getElementById('DigitalClock').innerHTML = h + ':' + m + ':' + s;
}
</script>
</body>
</html>
