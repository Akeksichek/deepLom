

document.addEventListener("DOMContentLoaded", function (event) {
    document.getElementById("logOpen").addEventListener("click", function () {
        document.getElementById("modalLog").classList.add("open");
    });
    document.getElementById("logClose").addEventListener("click", function () {
        this.closest(".modalLog").classList.remove("open");
    });
    document.getElementById("regOpen").addEventListener("click", function () {
        document.getElementById("modalReg").classList.add("open");
    });
    document.getElementById("regClose").addEventListener("click", function () {
        this.closest(".modalReg").classList.remove("open");
    });



    document.getElementById("history_list").addEventListener("click", function() {
        document.querySelector(".history").classList.add("active");
        document.getElementById("history_list").style.animationName = "NULL";
    });
    document.getElementById("h_close").addEventListener("click", function() {
        this.closest(".history").classList.remove("active");
    });

});
