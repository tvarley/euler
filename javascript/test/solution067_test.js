var assert = require('assert');
var solution067 = require('../src/euler/solution067');

describe('Solution067', function() {
  describe('answer', function() {
    it('will answer problem 067', function() {
      assert.equal(solution067.answer(), 7273);
    });
  });
});