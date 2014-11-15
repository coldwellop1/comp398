// Retrieve
var Ponies = require('mongodb');

// Connect to the db
Ponies.connect("mongodb://coldwellop1:comp398@ds051980.mongolab.com:51980/p2", function(err, db) {
  if(err) { return console.dir(err); }
  
var psych = {premier: 2006, network: 'usa', creator: '', genre:'', seasons:};

function pausecomp(millis) 
{
var date = new Date();
var curDate = null;

do { curDate = new Date(); } 
while(curDate-date < millis);
} 
  

  
  var collection = db.collection('TvShows');
  
  //Find and delete previous collection
  if (collection.find(function(err, result) {}) !== null) {
		collection.remove(function(err, result) {});
		console.dir("Previous doc collection removed");
	}
	
	collection.insert(psych, function(err, result){});
  
  console.log("Collection Populated!");
  
});
