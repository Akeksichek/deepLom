addEventListener("DOMContentLoaded", () => {
  
fetch("http://localhost:9090/save")
    .then((response) => {
      return response.json();
    })
    .then((data) => {
      user_data = data;
      create_session(user_data);
    });
    
    
  function create_session(user_data)
  {
    if( user_data.login == " " && user_data.email == " " && user_data.role == " " ){
      document.getElementById("history_list").style.display = "none";
    } 
    else if( user_data.login != " " && user_data.email != " " && user_data.role != " " )
    {
      document.getElementById("history_list").innerHTML = user_data.login;
      document.getElementById("noauth_user_auth").style.display = "none";
      document.getElementById("noauth_user_reg").style.display = "none";
      document.getElementById("auth_user").style.display = "block";
      view_history();
    }
  }

  function view_history() {
    fetch("http://localhost:9090/history")
        .then(response => response.json())
        .then(data => {
            let historyList = data.history_list;

            // Отрисовка строк истории
            historyList.forEach((item, index) => {
                history_rowRender(index, item); // Предположим, что эта функция добавляет элементы в DOM
            });

            // Изменение элементов после того, как они были добавлены в DOM
            historyList.forEach((item, index) => {
                // Здесь мы предполагаем, что элементы создаются с id в формате `h_category${index}` и `h_time${index}`
                let categoryElement = document.getElementById(`h_category${index}`);
                let timeElement = document.getElementById(`h_time${index}`);

                if (categoryElement) {
                    categoryElement.innerHTML = all_categories[item.category];
                } else {
                    console.error(`Element with id h_category${index} not found`);
                }

                if (timeElement) {
                    timeElement.innerText = item.time;
                } else {
                    console.error(`Element with id h_time${index} not found`);
                }
            });
        })
        .catch(error => {
            console.error('Error fetching history:', error);
        });
}


let all_categories = {
  "albom": "Фото на альбом",
  "passport": "Фото на паспорт",
  "marry": "Свадебные фото",
  "crutoe": "Художественные фото",
  "advert": "Рекламные фото",
  "family": "Семейные фото"
};
// Пример функции history_rowRender
function history_rowRender(index, item) {
    
    // h_row div
    // row_desk div
      // h_category p
      // h_time p
    // repeat_btn div
      //btnNav div img src="../uploads/repeat_btn.png"




    let container = document.getElementById('h_table');
    let h_row = document.createElement('div');
    h_row.className = 'h_row';

    let row_desk = document.createElement('div');
    row_desk.className = 'row_desk';
    h_row.appendChild(row_desk);

    let h_category = document.createElement('p');
    h_category.id = `h_category${index}`;
    h_category.className = 'h_category';
    row_desk.appendChild(h_category);

    let h_time = document.createElement('p');
    h_time.id = `h_time${index}`;
    h_time.className = 'h_time';
    row_desk.appendChild(h_time);

    let repeat_btn = document.createElement('div');
    repeat_btn.className = 'repeat_btn';
    h_row.appendChild(repeat_btn);
    let btnNav = document.createElement('img');
    btnNav.className = 'btnNav';
    btnNav.src = "../uploads/repeat_btn.png";
    repeat_btn.appendChild(btnNav);

    container.appendChild(h_row);
}

});

