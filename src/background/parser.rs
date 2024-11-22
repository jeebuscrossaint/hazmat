use std::{error::Error, io, process};

pub fn import -> Result<(), Box<dyn Error>> {
	// build csv reader and iterate over each record
	let mut rdr = csv::Reader::from_reader(io::stdin());
	for result in rdr.records() {
		let record = result?;
	}
}
