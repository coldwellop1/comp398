// Retrieve
var Ponies = require('mongodb');

// Connect to the db
Ponies.connect("mongodb://coldwellop1:comp398@ds051980.mongolab.com:51980/p2", function(err, db) {
  if(err) { return console.dir(err); }
  
var psych = {title: "Psych", premier: "2006", network: "USA", creator: "Steve Franks", genre:"Comedy", seasons: 8};
var chuck = {title: "Chuck", premier: "September 24, 2007", network: "NBC", creator: "Josh Shwartz and Chris Fedak", genre: "Action/Comedy", seasons: 5};
var bones = {title: "Bones", premier: "September 13, 2005", network: "FOX", creator: "Hart Hanson", genre: "Crime", seasons: 10};
var howIMetYourMother = {title: "How I Met Your Mother", premier: "September 19, 2005", network: "CBS", creator: "Carter Bays and Craig Thomas", genre: "Comedy", seasons: 9};

var theBigBangTheory = {title: "The Big Bang Theory", premier: "2006", network: "TBS", creator: "Chuck Lorre", genre: "Comedy", seasons: 10};
var gilmoreGirls = {title: "Gilmore Girls", premier: "2000", network: "The CW", creator: "Amy Sherman-Palladino", genre: "Comedy/Drama", seasons: 7};
var modernFamily = {title: "Modern Family", premier: "2009", network: "ABC", creator: "Steven Levitan", genre: "Comedy", seasons: 6};
var castle = {title: "Castle", premier: "2009", network: "ABC", creator: "Andrew W. Marlowe", genre: "Comedy/Crime/Drama", seasons: 7};

var breakingBad = {title: "Breaking Bad", premier: "2008", network: "AMC", creator: "Vince Gilligan", genre: "Drama", seasons: 5};
var familyGuy = {title: "Family Guy", premier: "1999", network: "FOX", creator: "Seth Macfarlane", genre: "Comedy", seasons:15};
var starTrekTNG = {title: "Star Trek TNG", premier: "1987", network: "CBS", creator: "Gene Roddenberry", genre: "Sci-Fi", seasons:7};
var theSimpsons = {title: "The Simpsons", premier: "1989", network: "FOX", creator: "Matt Groenig", genre: "Comedy", seasons: 524};

var episodeCollect = [psych, chuck, bones, howIMetYourMother, theBigBangTheory, gilmoreGirls, modernFamily, castle, breakingBad, familyGuy, starTrekTNG, theSimpsons];
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
	
	collection.insert(episodeCollect, function(err, result){});
  
  console.log("Collection Populated!");
  
});




