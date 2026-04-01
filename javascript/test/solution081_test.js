var assert = require('assert');
var solution081 = require('../src/euler/solution081');

describe('Solution081', function() {
  describe('answer', function() {
    it('will answer problem 081', function() {
      assert.equal(solution081.answer(), 427337);
    });
  });
});