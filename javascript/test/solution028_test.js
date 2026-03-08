var assert = require('assert');
var solution028 = require('../src/euler/solution028');

describe('Solution028', function() {
  describe('answer', function() {
    it('will answer problem 028', function() {
      assert.equal(solution028.answer(), 669171001);
    });
  });
});
