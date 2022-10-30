var when, 
		offset,
		mins,
		segments = [],
		ampm,
		hours, 
		totalMins=[],
		diff;

//parse parameters
str=str.split('-');

for (var i = 0; i<str.length; i++) {
	//grab am pm suffix
	ampm = str[i].slice(str[i].length-2);
	str[i]= str[i].substr(0, str[i].length-2);
	//split the rest
	segments = str[i].split(':');
	hours= parseInt(segments[0]);
	mins=parseInt(segments[1]);

	//normalize mins
	if ((hours==12) && (ampm=='am')){
		console.log('zeroing hours');
		hours=0;
	}

	if ((ampm=='pm') && (hours != 12)){
		hours = hours+12;
	}

	combomins=((hours*60)+mins);
	totalMins.push((hours * 60) + mins);
}

//account for next day
if (totalMins[1]<totalMins[0]){

	totalMins[1] += 1440;
}


return totalMins[1]-totalMins[0];

}
