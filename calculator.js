<!DOCTYPE html>
<html>
<head>
  <title> Digital Clock </title>
  <style>
    
     .title{
       margin-bottom: 10px;
       text-align: center;
       width: 210px;
       color: blue;
       border: solid black 2px;
    }
    input [type = 'button']{
      background-color: black;
      color: white;
      border: solid black 2px;
      width: 100%;
    }
    input [type = 'text']{
      background-color: white;
      border: solid black 2px;
      width: 100%;    
    }  

  </style>
</head>
<body>
<div class = 'title'> Calculator </div>
<table border = '0'>
  <tr>
    <td colspan = '3'>< input type ='text' id = 'result'></td>
    <td>< input type ='button' value = 'c' onclick = 'clr()' ></td>
  </tr>
  <tr>
    <td>< input type ='button' value = '1' onclick = 'display('1')'></td>
    <td>< input type ='button' value = '2' onclick = 'display('2')'></td>
    <td>< input type ='button' value = '3' onclick = 'display('3')'></td>
    <td>< input type ='button' value = '/' onclick = 'display('/')'></td>
  </tr>
  <tr>
    <td>< input type ='button' value = '4' onclick = 'display('4')'></td>
    <td>< input type ='button' value = '5' onclick = 'display('5')'></td>
    <td>< input type ='button' value = '6' onclick = 'display('6')'></td>
    <td>< input type ='button' value = '-' onclick = 'display('-')'></td>
  </tr>
  <tr>
    <td>< input type ='button' value = '7' onclick = 'display('7')'></td>
    <td>< input type ='button' value = '8' onclick = 'display('8')'></td>
    <td>< input type ='button' value = '9' onclick = 'display('9')'></td>
    <td>< input type ='button' value = '+' onclick = 'display('+')'></td>
  </tr>
  <tr>
    <td>< input type ='button' value = '.' onclick = 'display('.')'></td>
    <td>< input type ='button' value = '0' onclick = 'display('0')'></td>
    <td>< input type ='button' value = '=' onclick = 'equate()'></td>
    <td>< input type ='button' value = '*' onclick = 'display('*')'></td>
  </tr>
<script type = 'text/javascript'>
  function clr(){
    document.getElementByid('result').value = '';
  }
  function display(val){
    document.getElementByid('result').value += val;
  }
  function equate(){
    Let x = document.getElementByid('result').value;
    Let y = eval(x);
    document.getElementByid('result').value = y;
  }      

</script>
</body>
</html>
