const char MainPage[] PROGMEM = R"=====(
  <!DOCTYPE html>
<html>

<head>
  <title>BẢNG ĐIỀU KHIỂN</title>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
  <link href="https://fonts.googleapis.com/css?family=Open+Sans:300,400,600" rel="stylesheet">
  <style>
    /* css cho nhiệt độ ,độ ẩm.. */
    .side-by-side {
      display: inline-block;
      vertical-align: middle;
      position: relative;
    }

    .humidity-icon {
      background-color: #3498db;
      margin-left: 99px;
      width: 40px;
      height: 40px;
      border-radius: 50%;
      line-height: 40px;
    }

    .humidity {
      font-weight: 300;
      font-size: 30px;
      color: #3498db;
    }

    .temperature-icon {
      background-color: #f39c12;
      margin-left: -19px;
      width: 40px;
      height: 40px;
      border-radius: 50%;
      line-height: 40px;
    }

    .temperature {
      font-weight: 300;
      font-size: 30px;
      color: #f39c12;
    }

    .superscript {
      font-size: 20px;
      font-weight: 600;
      position: absolute;
      right: -20px;
      top: 8px;
    }

    .data {
      padding: 10px;
    }

    /*  css cho nút tự động */
    .switch {
      position: relative;
      display: inline-block;
      width: 60px;
      height: 34px;
      top: -5px;
    }


    .switch input {
      opacity: 0;
      width: 0;
      height: 0;
    }

    .slider {
      position: absolute;
      cursor: pointer;
      top: 0;
      left: 0;
      right: 0;
      bottom: 0;
      background-color: #ccc;
      -webkit-transition: .4s;
      transition: .4s;
    }

    .slider:before {
      position: absolute;
      content: "";
      height: 26px;
      width: 26px;
      left: 6px;
      bottom: 4px;
      background-color: white;
      -webkit-transition: .4s;
      transition: .4s;
    }

    input:checked+.slider {
      background-color: #2196F3;
    }

    input:focus+.slider {
      box-shadow: 0 0 1px #2196F3;
    }

    input:checked+.slider:before {
      -webkit-transform: translateX(26px);
      -ms-transform: translateX(26px);
      transform: translateX(26px);
    }

    /* Rounded sliders */
    .slider.round {
      border-radius: 60px;
    }

    .slider.round:before {
      border-radius: 50%;
    }

    /*   CSS cho giao diện */
    body {
      text-align: center;
      background-color: #160d02d7;
      color: white
    }

    input {
      height: 25px;
      width: 270px;
      font-size: 20px;
      margin: 10px auto;
    }

    #content {
      border: white solid 1px;
      padding: 5px;
      height: 550px;
      width: 420px;
      border-radius: 30px;
      margin: 0 auto
    }

    .ledstatus {
      outline: none;
      margin: 38px 20px 20px;
      width: 60px;
      height: 60px;
      border-radius: 50%;
      -moz-border-radius: 50%;
      -webkit-border-radius: 50%;
      color: white;
      font-size: 20px;
      font-weight: bold;
    }

    #ledstatus1 {
      border: solid 2px #2196F3;
      background: #2196F3;
    }

    #ledstatus2 {
      border: solid 2px #2196F3;
      background: #2196F3;
    }

    #ledstatus3 {
      border: solid 2px #2196F3;
      background: #2196F3;
    }

    #ledstatus4 {
      border: solid 2px #2196F3;
      background: #2196F3 ;
    }

    #ledconnect {
      outline: none;
      margin: 70px 10px -1px 5px;
      width: 15px;
      height: 15px;
      border: solid 1px #00EE00;
      background-color: #00EE00;
      border-radius: 50%;
      -moz-border-radius: 50%;
      -webkit-border-radius: 50%;
    }

    .button {
      height: 60px;
      width: 100px;
      margin: 20px 20;
      background-color: #ebb608;
      border-radius: 30px;
      outline: none;
      color: white;
      font-size: 20px;
      font-weight: bold;
    }

    .button_all {
      height: 70px;
      width: 140px;
      margin: 15px 0;
      outline: none;
      color: white;
      font-size: 20px;
      font-weight: bold;
    }

    #button_on {
      background-color: #2196F3;
      border-radius: 10px;
    }

    #button_off {
      background-color: #d4140e;
      border-radius: 10px;
    }

    .button_setup {
      height: 30px;
      width: 280px;
      margin: 10px 0;
      background-color: #3c3ebc;
      border-radius: 10px;
      outline: none;
      color: white;
      font-size: 20px;
      font-weight: bold;
    }

    .button_wifi {
      height: 50px;
      width: 90px;
      margin: 10px 0;
      outline: none;
      color: white;
      font-size: 15px;
      font-weight: bold;
    }

    #button_save {
      background-color: #00BB00;
      border-radius: 5px;
    }

    #button_restart {
      background-color: #FF9900;
      border-radius: 5px;
    }

    #button_reset {
      background-color: #CC3300;
      border-radius: 5px;
    }
  </style>
  <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">

</head>

<body>
  <div>
    <h1>
      <center>BẢNG ĐIỀU KHIỂN</center>
    </h1>
  </div>
  <div id="content">
    <div id="homecontrol" style="height:120px;">
      <div></div>
      <div>
        <!--   nhiệt độ và độ ẩm -->
        <div class="data">
          <div class="side-by-side temperature-icon">
            <center>
              <svg version="1.1" id="Layer_1" xmlns="http://www.w3.org/2000/svg"
                xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" width="15px" height="30px"
                viewBox="0 -2 10 22" enable-background="new 0 -2 10 22" xml:space="preserve">
                <path fill="#FFFFFF" d="M3.498,0.53c0.377-0.331,0.877-0.501,1.374-0.527C5.697-0.04,6.522,0.421,6.924,1.142
            c0.237,0.399,0.315,0.871,0.311,1.33C7.229,5.856,7.245,9.24,7.227,12.625c1.019,0.539,1.855,1.424,2.301,2.491
            c0.491,1.163,0.518,2.514,0.062,3.693c-0.414,1.102-1.24,2.038-2.276,2.594c-1.056,0.583-2.331,0.743-3.501,0.463
            c-1.417-0.323-2.659-1.314-3.3-2.617C0.014,18.26-0.115,17.104,0.1,16.022c0.296-1.443,1.274-2.717,2.58-3.394
            c0.013-3.44,0-6.881,0.007-10.322C2.674,1.634,2.974,0.955,3.498,0.53z" />
              </svg>
            </center>
          </div>
          <div class="side-by-side temperature"> <span id="nhietdos">0</span> *C</div>
          <div class="side-by-side humidity-icon">
            <center>
              <svg version="1.1" id="Layer_2" xmlns="http://www.w3.org/2000/svg"
                xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" "; width=" 15px" height="30px"
                viewBox="0 0 13 14" enable-background="new 0 0 13 14" xml:space="preserve">
                <path fill="#FFFFFF"
                  d="M1.819,6.217C3.139,4.064,6.5,0,6.5,0s3.363,4.064,4.681,6.217c1.793,2.926,2.133,5.05,1.571,7.057
            c-0.438,1.574-2.264,4.681-6.252,4.681c-3.988,0-5.813-3.107-6.252-4.681C-0.313,11.267,0.026,9.143,1.819,6.217"></path>
              </svg>
            </center>
          </div>
          <div class="side-by-side humidity"> <span id = "doams">0</span>%</span></div>
        </div>
      </div>
         <!--  chế độ auto -->
      <div style="text-align:center; margin-top: 15px;">
        <span style="font-size: 18px;color:greenyellow;text-align:center">Chế Độ Tự Động</span>
        <label class="switch">
          <input type="checkbox" id="auto1" name="auto1" ;>
          <span class="slider round"></span>
        </label>
      </div>

      <!--  led statuss -->
      
        <div>
          <input id="ledstatus1" class="ledstatus" type="button" value="OFF" />
          <input id="ledstatus2" class="ledstatus" type="button" value="OFF" />
          <input id="ledstatus3" class="ledstatus" type="button" value="OFF" />
          <input id="ledstatus4" class="ledstatus" type="button" value="OFF" />
        </div>
        
        <div>
          <button class="button" onclick=getbutton(1)>1</button>
          <button class="button" onclick=getbutton(2)>2</button>
          <button class="button" onclick=getbutton(3)>3</button>
          <button class="button" onclick=getbutton(4)>4</button>
        </div>
        <div style="text-align:center;" >
          <button id="button_on" class="button_all" onclick="getbuttonall('on')">Turn on all</button>
          <button id="button_off" class="button_all" onclick="getbuttonall('off')">Turn off all</button>
        </div>
        <center><input class="button_setup" type="button" onclick="configurewifi()" value="Thiết Lập wifi" /></center>
        <center>IP connected: <b><span id="ipconnected"></span></b></center>
    </div>
    <div id="wifisetup" style="height:340px; font-size:20px; display:block;text-align: center;">
      <div>SSID: </div>
      <div><input id="ssid" /></div>
      <div>Password: </div>
      <div><input id="pass" /></div>
      <div>
        <button id="button_save" class="button_wifi" onclick="writeEEPROM()">SAVE</button>  
        <button id="button_restart" class="button_wifi" onclick="restartESP()">RESTART</button>
        <button id="button_reset" class="button_wifi" onclick="clearEEPROM()">RESET</button>
      </div>
      <div><input class="button_setup" type="button" onclick="backHOME()" value="Back home" /></div>
      <div id="reponsetext"></div>
    </div>
  </div>


  <div>
    <center><input id="ledconnect" type="button" />Connection status </center>
  </div>
  </div>
  <div id="footer">
    <p><i>
        <center>
          Sinh viên thực hiện <b>Nguyễn Đức Minh</b>
          <br>Mã Sinh viên: <b>1781510049</b>
      </i>
      </center>
    </p>
  </div>
  <script>
    //-----------Hàm khởi tạo đối tượng request----------------
    function create_obj(){
          td = navigator.appName;
          if(td == "Microsoft Internet Explorer"){
            obj = new ActiveXObject("Microsoft.XMLHTTP");
          }else{
            obj = new XMLHttpRequest();
          }
          return obj;
        }
        //------------Khởi tạo biến toàn cục-----------------------------
        var xhttp = create_obj();//Đối tượng request cho setup wifi
        var xhttp_statusD = create_obj();//Đối tượng request cho cập nhật trạng thái
        var d1,d2,d3,d4;
        var ledconnect = 1;
        //===================Khởi tạo ban đầu khi load trang=============
        window.onload = function(){
          document.getElementById("homecontrol").style.display = "block";
          document.getElementById("wifisetup").style.display = "none";
          getIPconnect();//Gửi yêu cầu lấy IP kết nối
          getstatusD();//Gửi yêu cầu lấy trạng thái các chân điều khiển
        }
        //===================IPconnect====================================
        //--------Tạo request lấy địa chỉ IP kết nối----------------------
        function getIPconnect(){
          xhttp.open("GET","/getIP",true);
          xhttp.onreadystatechange = process_ip;//nhận reponse 
          xhttp.send();
        }
        //-----------Kiểm tra response IP và hiển thị------------------
        function process_ip(){
          if(xhttp.readyState == 4 && xhttp.status == 200){
            //------Updat data sử dụng jvascripat----------
            ketqua = xhttp.responseText; 
            document.getElementById("ipconnected").innerHTML=ketqua;       
          }
        }
        //===========Cập nhật trạng thái Led===============================
        //-----------Gửi yêu cầu lấy trạng thái các chân D-----------------
        function getstatusD(){
          xhttp_statusD.open("GET","/getSTATUSD",true);
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
        }
        //-----------Kiểm tra và nhận response EEPROM----------------------
        function process_statusD(){
          if(xhttp_statusD.readyState == 4 && xhttp_statusD.status == 200){
            if(ledconnect == 1){
              ledconnect = 0;
              document.getElementById("ledconnect").style.background = "#222222";
            }else{
              ledconnect = 1;
              document.getElementById("ledconnect").style.background = "#00EE00";
            }
            //------Update trạng thái led tín hiệu lên panel điều khiển----
            var statusD = xhttp_statusD.responseText;
            var obj = JSON.parse(statusD);
            d1 = obj.D1;
            d2 = obj.D2;
            d3 = obj.D3;
            d4 = obj.D4;
            updateLedstatus(d1,d2,d3,d4);
          }
        }
        //----------Hiển thị trạng thái Led lên trình duyệt---------------------
        function updateLedstatus(D1,D2,D3,D4){
          if(D1 == "0"){
              document.getElementById("ledstatus1").value = "OFF";
              document.getElementById("ledstatus1").style.background = "#222222";
            }else{
              document.getElementById("ledstatus1").value = "ON";
              document.getElementById("ledstatus1").style.background = "#2196F3";
            }
            if(D2 == "0"){
              document.getElementById("ledstatus2").value = "OFF";
              document.getElementById("ledstatus2").style.background = "#222222";
            }else{
              document.getElementById("ledstatus2").value = "ON";
              document.getElementById("ledstatus2").style.background = "#2196F3";
            }
            if(D3 == "0"){
              document.getElementById("ledstatus3").value = "OFF";
              document.getElementById("ledstatus3").style.background = "#222222";
            }else{
              document.getElementById("ledstatus3").value = "ON";
              document.getElementById("ledstatus3").style.background = "#2196F3";
            }
            if(D4 == "0"){
              document.getElementById("ledstatus4").value = "OFF";
              document.getElementById("ledstatus4").style.background = "#222222";
            }else{
              document.getElementById("ledstatus4").value = "ON";
              document.getElementById("ledstatus4").style.background = "#2196F3";
            }
        }
        //===========Tạo và gửi request khi ấn button============================
        //-----------Thiết lập dữ liệu và gửi request ON/OFF D4---
        function getbutton(n){
          switch (n){
            case 1:
                var ledstatus1 = document.getElementById("ledstatus1").value;
                if(ledstatus1 == "ON"){
                  xhttp_statusD.open("GET","/D1off",true);
                }else{
                  xhttp_statusD.open("GET","/D1on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
            case 2:
                var ledstatus2 = document.getElementById("ledstatus2").value;
                if(ledstatus2 == "ON"){
                  xhttp_statusD.open("GET","/D2off",true);
                }else{
                  xhttp_statusD.open("GET","/D2on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
            case 3:
                var ledstatus3 = document.getElementById("ledstatus3").value;
                if(ledstatus3 == "ON"){
                  xhttp_statusD.open("GET","/D3off",true);
                }else{
                  xhttp_statusD.open("GET","/D3on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
            case 4:
               var ledstatus4 = document.getElementById("ledstatus4").value;
                if(ledstatus4 == "ON"){
                  xhttp_statusD.open("GET","/D4off",true);
                }else{
                  xhttp_statusD.open("GET","/D4on",true);
                }
                xhttp_statusD.onreadystatechange = process_statusD;
                xhttp_statusD.send();
                break;
          }
        }
        function getbuttonall(m){
          if(m == "on"){
            xhttp_statusD.open("GET","/Allon",true);
          }else if(m=="off"){
            xhttp_statusD.open("GET","/Alloff",true);
          }
          xhttp_statusD.onreadystatechange = process_statusD;
          xhttp_statusD.send();
        }
        setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getnhietdo();
  getdoam();
}, 1000); //2000mSeconds update rate
//-----------------------------------
function getnhietdo() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("nhietdos").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "docnhietdo", true);
  xhttp.send();
}

function getdoam() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("doams").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "docdoam", true);
  xhttp.send();
}
        //===========Configure WiFi=====================================
        function configurewifi(){
          document.getElementById("homecontrol").style.display = "none";
          document.getElementById("wifisetup").style.display = "block";
        }
        //-----------Thiết lập dữ liệu và gửi request ssid và password---
        function writeEEPROM(){
          if(Empty(document.getElementById("ssid"), "Please enter ssid!")&&Empty(document.getElementById("pass"), "Please enter password")){
            var ssid = document.getElementById("ssid").value;
            var pass = document.getElementById("pass").value;
            xhttp.open("GET","/writeEEPROM?ssid="+ssid+"&pass="+pass,true);
            xhttp.onreadystatechange = process;//nhận reponse 
            xhttp.send();
          }
        }
        function clearEEPROM(){
          if(confirm("Do you want to delete all saved wifi configurations?")){
            xhttp.open("GET","/clearEEPROM",true);
            xhttp.onreadystatechange = process;//nhận reponse 
            xhttp.send();
          }
        }
        function restartESP(){
          if(confirm("Do you want to reboot the device?")){
            xhttp.open("GET","/restartESP",true);
            xhttp.send();
            alert("Device is restarting! If no wifi is found please press reset!");
          }
        }
        //-----------Kiểm tra response -------------------------------------------
        function process(){
          if(xhttp.readyState == 4 && xhttp.status == 200){
            //------Updat data sử dụng javascript----------
            ketqua = xhttp.responseText; 
            document.getElementById("reponsetext").innerHTML=ketqua;       
          }
        }
       //============Hàm thực hiện chứ năng khác================================
       //--------Cập nhật trạng thái tự động sau 2000 giây----------------------
        setInterval(function() {
          getstatusD();
        },2000);
       //--------Load lại trang để quay về Home control-------------------------
        function backHOME(){
          window.onload();
        }
       //----------------------------CHECK EMPTY--------------------------------
       function Empty(element, AlertMessage){
          if(element.value.trim()== ""){
            alert(AlertMessage);
            element.focus();
            return false;
          }else{
            return true;
          } 
       }
       //------------
       function tu_dong(){
       
              document.getElementById('auto1 ').onclick = function(e){
                /*if (this.checked){
                    xhttp.open("GET","/tudong1",true);
                     xhttp.send();
                }else{
                 Serial.print("tawt nhes");
                }
               xhttp.send();*/
                if (this.checked){
                    alert("Bạn vừa thích freetuts.net");
                }
                else{
                    alert("Bạn vừa bỏ thích freetuts.net");
                }
              };
          }



       //------------------------------------------------------------------------
      </script>
   </body> 
  </html>
)=====";
