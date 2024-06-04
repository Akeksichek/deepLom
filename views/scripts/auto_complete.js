
addEventListener("DOMContentLoaded", () => {

    fetch("http://localhost:9090/save")
    .then((response) => {return response.json()})
    .then((data) => {
        data_autoComplete(conf_data(data), data);
    })

    function conf_data(user_data)
    {
        if( user_data.login != " " && user_data.email != " " && user_data.role != " " )
            return true;
        else
            return false;
    }

    function data_autoComplete(func, user_data)
    {
        if( !func )
            return;
        document.getElementById("email").value = user_data.email;
    }

    //категория выбор
    document.getElementById("category").addEventListener("change", function() {
        var selectedOption = this.options[this.selectedIndex];
        var selectedText = selectedOption.text;
        console.log(selectedText);
        document.getElementById("category_title").innerText = selectedText;
    });

    

})