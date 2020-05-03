const FPS = 60;

document.getElementById("Time").innerHTML = "Time";
document.getElementById("Hours").innerHTML = "Hours";
document.getElementById("Minutes").innerHTML = "Minutes";
document.getElementById("Seconds").innerHTML = "Seconds";
setInterval(update, 1000 / FPS);

function numberWithCommas(x) {
    return x.toString().replace(/\B(?=(\d{3})+(?!\d))/g, ",");
}

function update() {
    let date1 = new Date();
    const date2 = new Date('6/10/2020');
    
    let diffTime = Math.abs(date2 - date1);
    
    let diffSeconds = Math.floor(diffTime / 1000);
    let diffMinutes = Math.floor(diffSeconds / 60);
    let diffHours = Math.floor(diffMinutes / 60);
    let diffDays = Math.floor(diffHours / 24);

    let secondsText = numberWithCommas(diffSeconds);
    let minutesText = numberWithCommas(diffMinutes);
    let hoursText = numberWithCommas(diffHours);
    let daysText = numberWithCommas(diffDays);
    
    document.getElementById("Hours").innerHTML = "" + hoursText;
    document.getElementById("Minutes").innerHTML = "" + minutesText;
    document.getElementById("Seconds").innerHTML = "" + secondsText;

    document.getElementById("Time").innerHTML = "" + daysText + " days, " 
	+ numberWithCommas(diffHours % 24) + " hours, "
	+ numberWithCommas(diffMinutes % 60) + " minutes, and "
	+ numberWithCommas(diffSeconds % 60) + " seconds.";
}
