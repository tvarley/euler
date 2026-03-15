var assert = require('assert');
var solution050 = require('../src/euler/solution050');

describe('Solution050', function() {
  describe('answer', function() {
    it('will answer problem 050', function() {
      assert.equal(solution050.answer(), 997651);
    });
  });
});