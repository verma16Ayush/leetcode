function addEventListen() {
	let count = 0;
	document.getElementById("clickme").addEventListener("click", function xyz() {
		console.log("Button clicked times: ", ++count);
	});
}

addEventListen();
