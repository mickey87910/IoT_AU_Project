var dht;
var myFirebase;
var temp;
var humi;

function get_date(t) {
  var varDay = new Date(),
    varYear = varDay.getFullYear(),
    varMonth = varDay.getMonth() + 1,
    varDate = varDay.getDate();
  var varNow;
  if (t == "ymd") {
    varNow = varYear + "/" + varMonth + "/" + varDate;
  } else if (t == "mdy") {
    varNow = varMonth + "/" + varDate + "/" + varYear;
  } else if (t == "dmy") {
    varNow = varDate + "/" + varMonth + "/" + varYear;
  } else if (t == "y") {
    varNow = varYear;
  } else if (t == "m") {
    varNow = varMonth;
  } else if (t == "d") {
    varNow = varDate;
  }
  return varNow;
}

function get_time(t) {
  var varTime = new Date(),
    varHours = varTime.getHours(),
    varMinutes = varTime.getMinutes(),
    varSeconds = varTime.getSeconds();
  var varNow;
  if (t == "hms") {
    varNow = varHours + ":" + varMinutes + ":" + varSeconds;
  } else if (t == "h") {
    varNow = varHours;
  } else if (t == "m") {
    varNow = varMinutes;
  } else if (t == "s") {
    varNow = varSeconds;
  }
  return varNow;
}


boardReady({device: 'Egr7M'}, function (board) {
  board.samplingInterval = 250;
  dht = getDht(board, 11);
  document.getElementById('demo-area-01-show').innerHTML = '正在連線';
  myFirebase = new Firebase('https://dhtbase.firebaseio.com/');
  document.getElementById('demo-area-01-show').innerHTML = '連線完畢';
  dht.read(function(evt){
    temp = dht.temperature;
    humi = dht.humidity;
    document.getElementById('demo-area-01-show').innerHTML = (['temp:',temp,("<br/>"),'humi:',humi,("<br/>")].join(''));
    myFirebase.push({
      time: [get_date("ymd"),',',get_time("hms")].join(''),
      temp: temp,
      humi: humi
    });
  }, 10000);
});

