var assert = require('assert');
var solution090 = require('../src/euler/solution090');

describe('Solution090', function() {
  describe('answer', function() {
    it('will answer problem 090', function() {
      assert.equal(solution090.answer(), 1217);
    });
  });
});