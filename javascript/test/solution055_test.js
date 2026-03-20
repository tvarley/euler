var assert = require('assert');
var solution055 = require('../src/euler/solution055');

describe('Solution055', function() {
  describe('answer', function() {
    it('will answer problem 055', function() {
      assert.equal(solution055.answer(), 249);
    });
  });
});