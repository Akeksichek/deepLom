addEventListener("DOMContentLoaded", ()=>{


    
let user_event = document.getElementById("event_user");
let time = document.getElementById("time");
let transition = 10;
let close_time = 10;
const currenturl = window.location.href;



switch (currenturl) {
    case "http://localhost:9090/test_auth":
        user_event.innerHTML = "Авторизация";
        time.innerHTML = close_time;
        break;
        case "http://localhost:9090/signup":
            fetch("http://localhost:9090/save")
                .then((response) => {
                return response.json();
                })
                .then((data) => {
                user_data = data;
                if( user_data.login != " " )
                {
                    time.innerHTML = close_time;
                    user_event.innerHTML = "Регистрация";
                }
                else
                {
                    time.innerHTML = close_time;
                    document.getElementById("event_deskALL").innerHTML = "Пользователь с таким email уже существует";
                }
                });
            
        break;
    case "http://localhost:9090/logout":
        time.innerHTML = close_time;
        transition = 10;
        document.getElementById("event_deskALL").innerHTML = "Выход выполенен успешно";
        break;
    case "http://localhost:9090/signin":
        time.innerHTML = close_time;
        document.getElementById("event_deskALL").innerHTML = "Пароль или логин неверны";
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