### Homework 16: Examination Redux

Revisit your examination submission folder and the examination folder in the course repo. Using my feedback and reviewing the examination questions, resolve any issues that remain with your submissions and improve on them.

***

####Revisions made to exam:

#####`Problem 1`
* __Font size requires a unit to go with the numeric value.__
     * Originally we were given the code: `<font size=24>Lorem</font>`
     * This was unacceptable because these adjustments must be made in the css styling at the top of the file, so I replaced it with `span{ font-size: 36pt; }` within the style tags.  I attempted to keep the size 24, but there was no unit for which `size=24` was the same size as `span{ font-size: 24[insert unit here]; }`, so I messed around with it a little bit and found that in html5, `font-size: 36pt` was the most accurate size representation. 

* __Paragraph elements may be nested within list item elements.__
     * The only way to include paragraph elements within a list is if they do not have any list elements within them to interrupt the span.  To create the same effect as the given code, I replaced both `<p>` and `</p>` with a set of empty paragraph tags.


#####`Problem 2`
* __Incorrect font family - needs to be sans serif__
   * Instead of ignoring the font family as I did before, I added `
    font-family: sans-serif;` to my h1 css.



#####`Problem 3`
* __Not exactly the zebra background__
     * Apparently that wasn't amusing...
     * Removed the background image I used before and used the nth children to zebra stripe the table. 
     * I didn't want white in my table at all, so I colored the border in the table css code, and then wanted each of the two cell colors to be different than that, so I used nth even and nth odd to color them separately. 


#####`Problem 4`
* __Not sure what the visualization is actually depicting__
     * Since I never actually had the chance to finish this one, I have now done so.

* __No accessibility inclusion on the SVG beyond the text at the top and day count.__
