var assert = require('assert');
var solution014 = require('../src/euler/solution014');

describe('Solution014', function() {
  describe('answer', function() {
    it('will answer problem 014', function() {
      assert.equal(solution014.answer(), 837799);
    });
  });
});