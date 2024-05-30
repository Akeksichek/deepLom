addEventListener("DOMContentLoaded", ()=>{


    
let user_event = document.getElementById("event_user");
let time = document.getElementById("time");
let transition = 0;
let close_time = 0;
const currenturl = window.location.href;



switch (currenturl) {
    case "http://localhost:9090/test_auth":
        transition = 10, close_time = 10;
        user_event.innerHTML = "Авторизация";
        time.innerHTML = close_time;
        break;
    case "http://localhost:9090/signup":
        transition = 10;
        user_event.innerHTML = "Регистрация";
        break;
    case "http://localhost:9090/logout":
        transition = 10;
        document.getElementById("event_daskALL").innerHTML = "Выход выполенен успешно";
        break;
    default:
        break;
}

setTimeout(
    ()=>{
        document.getElementById("event_conf").click();
        console.log("time out");
    },
    transition * 1000
);

})