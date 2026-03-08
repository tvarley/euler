var assert = require('assert');
var solution019 = require('../src/euler/solution019');

describe('Solution019', function() {
  describe('answer', function() {
    it('will answer problem 019', function() {
      assert.equal(solution019.answer(), 171);
    });
  });
});