addEventListener("DOMContentLoaded", () => {
  
fetch("http://localhost:9090/save")
    .then((response) => {
      return response.json();
    })
    .then((data) => {
      user_data = data; // Сохраняем данные в переменную user_data
      create_session(user_data);
    });
    
    
  function create_session(user_data)
  {
    if( user_data.login == " " && user_data.email == " " && user_data.role == " " ){
      document.getElementById("noauth_user_auth").style.display = "block";
      document.getElementById("noauth_user_reg").style.display = "block";
      document.getElementById("auth_user").style.display = "none";
      console.log("user_data = \"_\"");
    }
    else if( user_data.login != " " && user_data.email != " " && user_data.role != " " ){
    document.getElementById("noauth_user_auth").innerHTML = user_data.login;
    document.getElementById("noauth_user_reg").style.display = "none";
    document.getElementById("auth_user").style.display = "block";
    }
  }

});

