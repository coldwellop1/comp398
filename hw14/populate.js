// Retrieve
var Ponies = require('mongodb');

// Connect to the db
Ponies.connect("mongodb://erose1:standard@ds051160.mongolab.com:51160/comp398_hw_14", function(err, db) {
  if(err) { return console.dir(err); }
  
  var Anat = "A B C# D E F# G#";
  var Bflat = "Bb C D Eb F G A";
  var Bnat = "B C# D# E F# G# A#";
  var Cnat = "C D E F G A B";
  var Csharp = "C# D# E# F# G# A# B#";  
  var Dnat = "D E F# G A B C#";
  var Eflat = "Eb F G Ab Bb C D";
  var Enat = "E F# G# A B C# D#";
  var Fnat = "F G A Bb C D E";
  var Fsharp = "F# G# A# B C# D# E#";

function donothing() {
	var timeWaster = [123, 234, 346234, "Not sure if this'll actually help, but why not?!"];
}
  
  var MajScales = [Anat, Bflat, Bnat, Cnat, Csharp, Dnat, Eflat, Enat, Fnat, Fsharp];
  
  var collection = db.collection('scales');
  
  //Find and delete previous collection
  if (collection.find(function(err, result) {}) !== null) {
		collection.remove(function(err, result) {});
		console.dir("Previous doc collection removed");
	}
	
  for (var i = 0; i < 250; i++){
	collection.insert(MajScales, function(err, result){});
	setTimeout(donothing(), 1000);
  }
  
  console.log("Collection Populated!");
  
});
