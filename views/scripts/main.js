

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
});
